n, k = list(map(int, input().split()))
finish = False
length = 1
for i in range(n-1):
    length = length * 2 + 1    
while n!=1:
    gran = length // 2 + 1
    if k == gran:
        print(n)
        finish = True
        break
    if k < gran:
        length = length // 2
        n -= 1
    if k > gran:
        k -= (length // 2 + 1)
        length = length // 2
        n -= 1  
if not finish:
    print(1)