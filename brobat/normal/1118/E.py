n, k = map(int, input().split())
if(n > k*(k-1)):
    print("NO")
else:
    print("YES")
    t = 0
    for i in range(1, k):
        for j in range(i + 1, k + 1):
            print(f"{i} {j}")
            t += 1
            if(t==n):
                exit()
            print(f"{j} {i}")
            t += 1
            if(t==n):
                exit()