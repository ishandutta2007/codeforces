n = int(input())
line = list(map(int, input().split()))
if max(sorted(line)) == 0 and min(sorted(line)) == 0:
    print("NO")
else:
    s = 0
    for i in range(n):
        s += line[i]
    if s != 0:
        print("YES")
        print(1)
        print(1, n)
    else:
        for i in range(n):
            if line[i] != 0:
                print("YES")
                print(2)
                print(1, i + 1)
                print(i+2, n)
                break