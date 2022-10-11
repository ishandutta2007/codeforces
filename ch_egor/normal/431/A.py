arr = list(map(int, input().split()))
st = input()
answer = 0
for i in st:
    answer += arr[int(i) - 1]
print(answer)