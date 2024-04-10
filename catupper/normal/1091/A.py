y, b, r = map(int, raw_input().split())

ans = y*3 + 3
ans = min(ans, b*3)
ans = min(ans, r*3-3)

print ans