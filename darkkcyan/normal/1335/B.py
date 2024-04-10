import string
for _ in range(int(input())):
    n, a, b = map(int, input().split())
    alphas =  string.ascii_lowercase[:b]
    alphas = alphas * (a // b) +  alphas[:a % b]
    print(alphas * (n // a) + alphas[:n % a])