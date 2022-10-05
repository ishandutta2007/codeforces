t = int(input())
for _ in range(t):
    n, k = map(int,input().split())
    l = list(map(int,input().split()))
    OUT = [n // 2] * (2 * k + 2)
    extraL = [0] * (2 * k + 2)
    extraR = [0] * (2 * k + 2)
    for i in range(n//2):
        left = l[i]
        right = l[n - 1 - i]
        OUT[left + right] -= 1
        extraL[min(left,right)] += 1
        extraR[max(left,right) + k + 1] += 1

    curr = 0
    for i in range(2 * k + 2):
        curr += extraR[i]
        extraR[i] = curr

    curr = 0
    for i in range(2 * k + 1, -1, -1):
        curr += extraL[i]
        extraL[i] = curr
        
    for i in range(2 * k + 2):
        OUT[i] += extraL[i] + extraR[i]

    print(min(OUT))