n = int(input())
mul = [0] * 10
can_zero = [True] * 10

for i in range(n):
    s = input()
    for j in range(len(s)):
        mul[ord(s[j]) - 97] += 10 ** (len(s) - 1 - j)
    can_zero[ord(s[0]) - 97] = False

max_zero, max_zero_idx = -1, -1

for i in range(10):
    if can_zero[i]:
        (max_zero, max_zero_idx) = max((max_zero, max_zero_idx), (mul[i], i))

mul[max_zero_idx] = 10 ** 20

mul.sort()
ans = 0
for i in range(10): ans += (9 - i) * mul[i]
print(ans)