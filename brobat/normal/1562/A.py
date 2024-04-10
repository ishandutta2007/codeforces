for _ in range(int(input())):
    # n = int(input())
    # arr = list(map(int, input().split()))
    l, r = map(int, input().split())
    print(r % max(r//2 + 1, l))