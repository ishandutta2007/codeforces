n = int(input())
a = [0] + list(map(int, input().split()))  # 
i = 1
while i < n:
    j = n - 1
    while j >= i:
        if a[j] > a[j + 1]:
            print(j, j + 1)
            a[j], a[j + 1] = a[j + 1], a[j]
        j -= 1
    i += 1