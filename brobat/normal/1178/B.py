s = input()
arr = []
i = 0
count = 0
while(i < len(s)):
    if(s[i]=='v'):
        count = 1
        i += 1
        while(i < len(s) and s[i]!='o'):
            count += 1
            i+=1
        arr.append(count)
        count = 0
    else:
        i+=1
o = []
i = 0
while(i < len(s)):
    if(s[i]=='o'):
        count = 1
        i += 1
        while(i < len(s) and s[i]!='v'):
            count += 1
            i+=1
        o.append(count)
        count = 0
    else:
        i+=1
if(count!=0):
    arr.append(count)
x = len(arr)
if(x==0 or x==1):
    print(0)
    exit()
for i in range(x):
    arr[i] -= 1
left = [arr[0]]
# right = [0]*(x-1)
for i in range(1, x-1):
    left.append(left[-1] + arr[i])
right = [arr[x-1]]
for i in range(x-2, 0, -1):
    right.append(right[-1] + arr[i])
# print(left)
# print(right)
# grr = [arr[0]]
# for i in range(1, x):
#     grr.append(grr[-1] + arr[i])
# ans = 0
# for i in range(x-1, 0, -1):
#     ans += arr[i]*grr[i-1]
# print(ans)
# print(arr)
# print(grr)
if(s[0]=='o'):
    o.pop(0)
# print(o)
ans = 0
for i in range(x-1):
    ans += left[i]*right[x-2-i]*o[i]
print(ans)