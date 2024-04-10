n = int(input())
l = list(map(int, input().split()))
rest = int(input())

tot = sum(l) + (n - len(l)) * rest
if tot > 0:
    print(n)
elif rest >= 0:
    print(-1)
else:
    curr = sum(l)

    bad = [(0, n - len(l))]
    
    for i in range(len(l)):
        if curr > 0:
            start = (curr + -rest - 1)//(-rest) + len(l) - i
        else:
            start = 0
            
        end = n - i

        if start <= end:
            bad.append((start,end))

        curr -= l[i]

    times = [0] * (n + 2)
    for s,e in bad:
        times[s] += 1
        times[e + 1] -= 1

    curr = 0
    for i in range(n + 1):
        curr += times[i]
        if curr == 0:
            print(i)
            break
    else:
        print(-1)