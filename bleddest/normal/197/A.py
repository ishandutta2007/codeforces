a, b, r = map(int, input().split())

print('First' if r * 2 <= min(a, b) else 'Second')