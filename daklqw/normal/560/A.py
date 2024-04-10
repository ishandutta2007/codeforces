input()
x=False
for i in map(int,input().split()):
    if i==1:x=True
if x:print('-1')
else:print('1')