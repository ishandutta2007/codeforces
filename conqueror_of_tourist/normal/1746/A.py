t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    l = list(map(int, input().split()))


    if sum(l):
        print('Yes')
    else:
        print('No')