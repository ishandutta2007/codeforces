import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, l = map(int, input().split())
    a = list(map(int, input().split()))
    a = [0] + a + [l]

    left = [0]
    for i in range(1,n+2):
        left.append(left[-1] + (a[i] - a[i-1])/i)
        
    right = [0]
    for i in range(1, n+2):
        right.append(right[-1] + (a[-i] - a[-i-1])/i)
    right = right[::-1]

    poss = []
    for i in range(n + 1):
        rs = n+1 - i
        ls = i+1
        if right[i+1] <= left[i + 1] and left[i] <= right[i]:
            dist = a[i+1] - a[i]
            #print(i, dist, left[i], right[i+1], ls, rs)
            if right[i+1] < left[i]:
                dist -= (left[i] - right[i+1])*rs
                curr = left[i]
            else:
                dist -= (right[i+1] - left[i])*ls
                curr = right[i+1]
            poss.append(curr + dist/(ls+rs))
    print(min(poss))