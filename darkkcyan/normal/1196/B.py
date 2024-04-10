from sys import stdin
q = int(stdin.readline())
for query in range(q):
    n, k = map(int, stdin.readline().split())
    a = list(map(int, stdin.readline().split()))
    ans = [0]
    for i in range(n):
        if k == 1:
            break
        if a[i] % 2 == 0:
            continue
        ans.append(i + 1)
        k -= 1
    if k != 1 or sum(a[ans[-1]:]) % 2 == 0:
        print("NO")
        continue
    print("YES")
    ans.append(n)
    print(' '.join(map(str, ans[1:])))