for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()
    ans = 0
    if(s[0]=="W"):
        ans += 1
    for i in range(n-1):
        if(s[i]=="W" and s[i+1]=="W"):
            ans += 2
        elif(s[i]=="L" and s[i+1]=="W"):
            ans += 1
    arr = []
    cnt = 0
    w = s.find("W")
    if(w==-1):
        ans += (2*k)
        ans -= 1
        if(ans<0):
            ans = 0
        print(min(ans, (2*n)-1))
        continue
    for i in range(w, n-1):
        if(cnt==0):
            if(s[i]=="W" and s[i+1]=="L"):
                cnt += 1
        else:
            if(s[i+1]=="L"):
                cnt += 1
            else:
                arr.append(cnt)
                cnt = 0
    arr.sort(reverse = True)
    # print(arr)
    # print(ans)
    ans += (2*k)
    while len(arr)>0:
        if((k-arr[-1])>=0):
            ans += 1
            # print('yay')
            k -= arr[-1]
            arr.pop()
        else:
            break
    print(min(ans, (2*n)-1))