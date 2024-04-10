input()
i = input()
l1 = []
l2 = []
while len(i.split('(')) > 1:
    l1.append(i.split('(')[0])
    i = '('.join(i.split('(')[1:])
    l2.append(i.split(')')[0])
    i = ')'.join(i.split(')')[1:])
l1.append(i)

l1 = ('_'.join(l1)).split('_')
l2 = ('_'.join(l2)).split('_')

for i in range(len(l2)-1,-1,-1):
    if l2[i] == '':
        l2.pop(i)

print(max(list(map(len,l1+['']))),len(l2))