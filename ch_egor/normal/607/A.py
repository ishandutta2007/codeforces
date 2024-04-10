import sys

MAX_X = 1000 * 1000 + 10

def main():
    n = int(sys.stdin.readline())

    arr = [0] * MAX_X
    cnt = [0] * MAX_X
    dp = [0] * MAX_X
    for i in range(n):
        x, c = list(map(int, sys.stdin.readline().split()))
        arr[x + 1] = c

    for i in range(1, MAX_X):
        cnt[i] += cnt[i - 1] + (arr[i] != 0)
    
    for i in range(1, MAX_X):
        dp[i] = dp[max(0, i - arr[i] - 1)] + cnt[i - 1] - cnt[max(0, i - arr[i] - 1)]

    answer = dp[MAX_X - 1]
    add = 0

    for i in range(MAX_X - 1, -1, -1):
        answer = min(answer, add + dp[i])
        add += (arr[i] != 0)

    sys.stdout.write(str(answer))

main()