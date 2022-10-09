from sys import stdin

for testcase in range(int(stdin.readline())):
    stdin.readline()
    print(*reversed(sorted(map(int, stdin.readline().split()))))