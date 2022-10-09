n = int(input())
print(sum(1 for i in range(1, n) if n % i == 0))