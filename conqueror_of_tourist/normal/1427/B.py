import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = input().strip()
    curr = n + 100
    streaks = []
    out = 0
    wins = k
    
    for i in range(n-1):
        if s[i] == 'W' and s[i+1] == 'W':
            out += 1
            
    for c in s:
        if c == 'W':
            streaks.append(curr)
            curr = 0
            out += 1
            wins += 1
        else:
            curr += 1
            
    streaks.sort()
    out += 2 * k
    for v in streaks:
        if v > 0 and v <= k:
            k -= v
            out += 1

    print(min([2 * n - 1,out,max(0,2 * wins - 1)]))