import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    evens = []
    odds = []
    for i in range(2 * n):
        if l[i] % 2:
            odds.append(i + 1)
        else:
            evens.append(i + 1)

    need = n - 1
    while need and len(evens) >= 2:
        need -= 1
        print(evens.pop(), evens.pop())
    while need and len(odds) >= 2:
        need -= 1
        print(odds.pop(), odds.pop())