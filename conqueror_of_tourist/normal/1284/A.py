n,m = map(int, input().split())
l1 = input().split()
l2 = input().split()

q = int(input())

for _ in range(q):
    y = int(input()) - 1
    print(l1[y % n] + l2[y % m])