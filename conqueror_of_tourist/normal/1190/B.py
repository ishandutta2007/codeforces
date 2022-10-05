n = int(input())
a = list(map(int,input().split()))

dupes = 0
dupeVal = -1
d = set()
for el in a:
    if el in d:
        dupes += 1
        dupeVal = el
    else:
        d.add(el)

inPlay = True
if dupes > 1:
    print('cslnb')
    inPlay = False
elif dupes == 1:
    if dupeVal == 0 or (dupeVal - 1) in d:
        print('cslnb')
        inPlay = False

if inPlay:
    finalSum = (n*(n-1))//2
    Sum = sum(a)
    if (Sum - finalSum) % 2 == 0:
        print('cslnb')
    else:
        print('sjfnb')