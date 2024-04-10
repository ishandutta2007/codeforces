n, m, k = map(int, input().split())

if n % 2 == 0:
    print('Marsel')
else:
    divisors = set()
    i = 1
    while i * i <= m:
        if m % i == 0:
            divisors.add(i)
            divisors.add(m // i)
        i += 1
    ans = 10 ** 18
    for x in divisors:
        if x >= k and x != m:
            ans = min(ans, x)
    if ans < 10 ** 18:
        print('Timur')
    else:
        print('Marsel')