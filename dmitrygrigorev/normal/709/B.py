n, a = list(map(int, input().split()))
line = list(map(int, input().split()))
line.sort()
if len(line) == 1:
    print(0)
else:    
    r1 = abs(line[-1] - line[1])
    otvet1 = min(abs(a - line[1]), abs(a - line[-1])) + r1
    r2 = abs(line[-2] - line[0])
    otvet2 = min(abs(a - line[-2]), abs(a - line[0])) + r2
    print(min(otvet1, otvet2))