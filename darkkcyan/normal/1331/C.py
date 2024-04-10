order = [5, 0, 2, 3, 1, 4]
num = int(input())
bin = []
for i in range(6):
    bin.append(num % 2)
    num //= 2

ans_bin = [bin[order[5 - i]] for i in range(6)]

ans = 0
for i in range(6):
    ans = ans * 2 + ans_bin[-1]
    ans_bin.pop()
print(ans)