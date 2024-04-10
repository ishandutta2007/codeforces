n, a = input(), map(lambda x: int(x)&1, raw_input().split())

ans = 0

if sum(a) % 2 == 1 or a.count(1):
    ans = 1


print ['Second', 'First'][ans]