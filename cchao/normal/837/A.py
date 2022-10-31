input()
print max(sum('A' <= c <= 'Z' for c in x) for x in raw_input().split())