n, m = map(int, input().split())

if n == 1:
    print(0)
    exit()

init = []
initi = []
final = []
fnali = []

for _ in range(m):
    x, y = map(int, input().split())
    init.append([x, y])
    initi.append([x, y])

for _ in range(m):
    x, y = map(int, input().split())
    final.append([x, y])
    fnali.append([x, y])

def check():
    #return

    things = [tuple(t) for t in init]
    assert len(set(things)) == m


for __ in range(4):
    for i in range(m):
        init[i] = initi[i][:]
        final[i] = fnali[i][:]

    #print(init, initi)
    #print(final, fnali)

    if __ % 2:
        for i in range(m):
            final[i][0] = n + 1 - final[i][0]
            init[i][0] = n + 1 - init[i][0]
    if __ // 2:
        for i in range(m):
            final[i][1] = n + 1 - final[i][1]
            init[i][1] = n + 1 - init[i][1]

    #print(init)
    #print(final)
    #print()

    
            
    rem = list(range(m))
    order = []
    moves = []
    for i in range(m):
        wx, wy = 1, i + 1

        poss = [(100 * abs(wx - init[r][0]) + abs(wy - init[r][1]), r) for r in rem]

        _, ind = min(poss)

        while init[ind][1] > i + 1:
            moves.append((init[ind][0], init[ind][1], init[ind][0], init[ind][1] - 1))
            init[ind][1] -= 1
            check()
            
        while init[ind][1] < i + 1:
            moves.append((init[ind][0], init[ind][1], init[ind][0], init[ind][1] + 1))
            init[ind][1] += 1
            check()
            
        while init[ind][0] > 1:
            moves.append((init[ind][0], init[ind][1], init[ind][0] - 1, init[ind][1]))
            init[ind][0] -= 1
            check()

        rem = [v for v in rem if v != ind]
        order.append(ind)

    f_order = list(range(m))
    f_order.sort(key = lambda x: 5 * n * final[x][0] + final[x][1] * (1 if final[x][0] == n else -1))

    #Send to n, i + 1 + n - m
    for i in range(m):
        ind = f_order[i]
        
        if i < m - 1: #Only matters for n=m=2
            moves.append((init[ind][0], init[ind][1], init[ind][0] + 1, init[ind][1]))
            init[ind][0] += 1
            check()
            
        while init[ind][1] > i + 1 + n - m:
            moves.append((init[ind][0], init[ind][1], init[ind][0], init[ind][1] - 1))
            init[ind][1] -= 1
            check()
            
        while init[ind][1] < i + 1 + n - m:
            moves.append((init[ind][0], init[ind][1], init[ind][0], init[ind][1] + 1))
            init[ind][1] += 1
            check()
            
        while init[ind][0] < n:
            moves.append((init[ind][0], init[ind][1], init[ind][0] + 1, init[ind][1]))
            init[ind][0] += 1
            check()

        assert init[ind][0] == n

    for i in range(m):
        ind = f_order[i]
        
        if final[ind][0] == n:
            while init[ind][1] > final[ind][1]:
                moves.append((init[ind][0], init[ind][1], init[ind][0], init[ind][1] - 1))
                init[ind][1] -= 1
                check()
            continue

        ind = f_order[i]
        while init[ind][1] > 1:
            moves.append((init[ind][0], init[ind][1], init[ind][0], init[ind][1] - 1))
            init[ind][1] -= 1
            check()

        while init[ind][0] > final[ind][0]:
            moves.append((init[ind][0], init[ind][1], init[ind][0] - 1, init[ind][1]))
            init[ind][0] -= 1
            check()

        while init[ind][1] < final[ind][1]:
            moves.append((init[ind][0], init[ind][1], init[ind][0], init[ind][1] + 1))
            init[ind][1] += 1
            check()

        assert init[ind][0] == final[ind][0]
        assert init[ind][1] == final[ind][1]

    if len(moves) <= 10800:
        #print(moves)

        if __ % 2:
            for i in range(len(moves)):
                moves[i] = (n + 1 - moves[i][0], moves[i][1], n + 1 - moves[i][2], moves[i][3])
                
        if __ // 2:
            for i in range(len(moves)):
                moves[i] = (moves[i][0],n + 1 -  moves[i][1], moves[i][2], n + 1 - moves[i][3])
                    
        print(len(moves))
        mm = [' '.join(map(str, m)) for m in moves]
        print('\n'.join(mm))
        exit()