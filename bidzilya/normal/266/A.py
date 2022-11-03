n = int(raw_input())

s = raw_input()

i = 0
ans = 0
while i < n:
    j = i
    while j + 1 < n and s[j + 1] == s[i]:
        j += 1
    ans += j - i + 1 - 1
    i = j + 1

print ans