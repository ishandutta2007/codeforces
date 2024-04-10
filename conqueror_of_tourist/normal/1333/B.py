import sys
input = sys.stdin.readline
 
t = int(input())
for _ in range(t):
    n = int(input())
    l1 = list(map(int,input().split()))
    l2 = list(map(int,input().split()))
    
    seen1 = False
    seenN = False
    works = True
    for i in range(n):
        if l2[i] > l1[i] and not seen1:
            works = False
            break
        if l2[i] < l1[i] and not seenN:
            works = False 
            break
        if l1[i] == 1:
            seen1 = True
        if l1[i] == -1:
            seenN = True
        
    if works:
        print('YES')
    else:
        print('NO')