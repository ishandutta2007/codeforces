import sys


def main():
    n = int(input())
    print(n // 2 - (n&1) * n)

main()