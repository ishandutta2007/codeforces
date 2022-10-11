import sys


def main():
    n, m = map(int, sys.stdin.readline().split())

    answer = 0

    for i in range(min(n + 1, m // 2 + 1)):
        answer = max(answer, i + max(0, min(m - i*2, (n - i) // 2)))

    print(answer)

main()