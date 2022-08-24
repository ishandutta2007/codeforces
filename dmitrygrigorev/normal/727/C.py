n = int(input())
sums = []
for i in range(2, n + 1):
    print("?", 1, i)
    answer = int(input())
    sums += [answer]
print("?", 2, 3)
s1 = int(input())
third = (sums[1] - sums[0] + s1) // 2
second = s1 - third
first = sums[0] - second
a = ["!", first, second, third]
for i in range(2, n - 1):
    a += [sums[i] - first]
print(" ".join(map(str, a)))