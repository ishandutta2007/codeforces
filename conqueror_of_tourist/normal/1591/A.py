t = int(input())
for _ in range(t):
    n = int(input())
    curr = 1
    alive = True

    w = list(map(int, input().split()))
    for i in range(n):
        if w[i] == 1:
            if i and w[i - 1]:
                curr += 5
            else:
                curr += 1
        else:
            if i and w[i-1] == 0:
                alive = False

    if alive:
        print(curr)
    else:
        print(-1)