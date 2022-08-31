n = int(input())
line = list(map(int, input().split()))
if n == 1 and line[0] != 0 and line[0] != 15:
    print(-1)
elif n == 1 and line[0] == 0:
    print("UP")
elif n == 1:
    print("DOWN")
else:
    if line[-1] > line[-2] and line[-1] == 15:
        print("DOWN")
    elif line[-1] > line[-2]:
        print("UP")
    elif line[-1] == 0:
        print("UP")
    else:
        print("DOWN")