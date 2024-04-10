import sys
input = sys.stdin.readline


t = int(input())
for _ in range(t):
    n = int(input())
    neck = sorted(list(map(int, input().split())))
    brac = sorted(list(map(int, input().split())))

    print(' '.join(map(str,neck)))
    print(' '.join(map(str,brac)))