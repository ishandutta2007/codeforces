l,l1,l2,l3 = [list(map(int,list(input()*0)+input().split(' '))),[],[],[]]
for elem in l:
    if elem > 0:
        l2.append(elem)
    elif elem < 0 and len(l1) == 0:
        l1.append(elem)
    else:
        l3.append(elem)
if len(l2) == 0:
    l3.sort()
    l2.append(l3.pop(0))
    l2.append(l3.pop(0))
for lis in [l1,l2,l3]:
    print(len(lis),end = '')
    for e in lis:
        print(' '+str(e),end = '')
    print()