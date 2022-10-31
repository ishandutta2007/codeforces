from sys import exit
k = int(input())
lets = [0]*26
str = input()
for c in str:
    lets[ord(c) - ord('a')] += 1

ans = ""
for i in range(0, 26):
    if lets[i] % k != 0:
        print(-1)
        exit()
    ans += chr(ord('a') + i) * (lets[i]//k)
ans *= k
print(ans)