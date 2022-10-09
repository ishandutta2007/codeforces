print('\n'.join(
    (lambda n, a, b: str(n // 2 * min(2 * a, b) + (n % 2) * a))(*map(int, input().split()))
    for i in range(int(input()))
))