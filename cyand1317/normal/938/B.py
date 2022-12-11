input()
a = list(map(int, input().split()))
L = int(1e6)

print(min(a[-1] - 1, L - a[0], L if len(a) == 1 else min(map(lambda i: max(a[i - 1] - 1, L - a[i]), range(1, len(a))))))