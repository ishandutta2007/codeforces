def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    got = [0]*(k+1)

    for i in range(0, k):
        for j in range(n//k):
            if arr[j*k+i]==1:
                got[i] += 1
    answer = 0

    for i in range(k):
        answer += min(got[i], n//k-got[i])

    print(answer)

main()