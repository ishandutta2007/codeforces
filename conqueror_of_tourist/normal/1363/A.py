import sys
t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    l = list(map(int, input().split()))
    odd = 0
    even = 0
    for v in l:
        if v % 2:
            odd += 1
        else:
            even += 1
            
    minOdd = max(x - even, 0)
    maxOdd = min(odd, x)

    works = False
    for i in range(minOdd, maxOdd + 1):
        if i % 2:
            works = True
            break

    print('Yes' if works else 'No')