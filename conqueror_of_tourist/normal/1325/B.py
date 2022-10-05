import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    input()
    print(len(set(map(int, input().split()))))