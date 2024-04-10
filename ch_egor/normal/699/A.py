import sys
input = sys.stdin.readline
print = sys.stdout.write

def main():
    n = int(input())
    st = input().rstrip()
    arr = list(map(int, input().split()))

    answer = 10**18
    for i in range(len(arr) - 1):
        if st[i] == "R" and st[i + 1] == "L":
            answer = min(answer, (arr[i + 1] - arr[i] + 1) // 2)
    if answer == 10**18:
        answer = -1
    print(str(answer))

main()