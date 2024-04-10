l, r, a = map(int, input().split())

ans = min(l, r)
l -= ans
r -= ans

g = min(max(l, r), a)
ans += g
a -= g

ans += a // 2

print(ans * 2)