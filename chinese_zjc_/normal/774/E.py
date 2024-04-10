# %%
s = input()
n = s.__len__()
m = int(input())

# %%
ans = 1145141919810
now = 0
for i in range(n):
    now = (now * 10 + int(s[i])) % m
# print(now)
for i in range(n):
    if s[i] != '0':
        ans = min(ans, now % m)
    now = (now * 10 + int(s[i]) * (1 - pow(10, n, m) + m)) % m
    # print(now)
# %%
print(ans)
# %%