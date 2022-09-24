n = int(input())
s = input()
i = 1
while (i < n) and s[i-1] <= s[i] :
    i = i + 1
print(s[:i-1]+s[i:])