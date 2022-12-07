for _ in range(int(input())):
    s = input()
    arr = [0]*len(s)
    d = False
    for i in range(len(s)):
        arr[i] = int(s[i])
    if(len(s) == 2):
        print(arr[0] + arr[1])
        continue
    for i in range(len(s) - 1, 0, -1):
        temp = arr[i] + arr[i-1]
        if(temp >= 10):
            arr[i] = temp%10
            arr[i-1] = temp//10
            for j in arr:
                print(j, end='')
            print()
            d = True
            break
    if(d):
        continue
    for i in range(len(s) - 1):
        if(arr[i] + arr[i+1] > arr[i]):
            arr[i] = arr[i] + arr[i+1]
            for j in range(len(s)):
                if(j==i+1):
                    continue
                print(arr[j], end='')
            print()
            d = True
            break
    if(d):
        continue
    arr[len(s)-2] = arr[len(s)-1] + arr[len(s)-2]
    for i in range(len(s) - 1):
        print(arr[i], end='')
    print()