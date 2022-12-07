arr = [0]
for i in range(1, 10000):
    if(i%3==0 or i%10==3):
        continue
    arr.append(i)

for _ in range(int(input())):
    n = int(input())
    print(arr[n])