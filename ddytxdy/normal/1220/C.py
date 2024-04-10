s=input()
m='z'
for i in s:
    if i>m:print('Ann')
    else:print('Mike')
    m=min(m,i)