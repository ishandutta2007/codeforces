n = int(input())
s = input()

cnt8 = 0
for x in s:
    if(x == '8'):
        cnt8 += 1

print(min(cnt8, n // 11))