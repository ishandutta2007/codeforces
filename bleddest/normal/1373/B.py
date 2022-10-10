t = int(input())

for i in range(t):
    s = input()
    cnt0, cnt1 = 0, 0
    for x in s:
        if x == '0':
            cnt0 += 1
        else:
            cnt1 += 1
    turn_count = min(cnt0, cnt1)
    if turn_count % 2 == 0:
        print('NET')
    else:
        print('DA')