n = int(input())
a = input()

for i in range(n):
    if a[i] == '0':
        print(i + 1)
        break
else:
    print(n)