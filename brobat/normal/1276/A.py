import re
for _ in range(int(input())):
    s = input()
    n = s.count("one")+s.count("two")-s.count("twone")
    x = [m.start() for m in re.finditer('one', s)]
    y = [m.start() for m in re.finditer('two', s)]
    z = [m.start() for m in re.finditer('twone', s)]
    arr = []
    for i in x:
        arr.append(i+2)
    for i in y:
        arr.append(i+2)
    for i in z:
        arr.append(i+3)
    arr.sort()
    print(n)
    for i in range(len(arr)-2):
        if((arr[i+1]==(arr[i]+1)) and (arr[i+2]==(arr[i]+2))):
            arr[i] *= -1
            arr[i+2] *= -1
    for i in range(len(arr)):
        if(arr[i]>0):
            print(arr[i], end= ' ')
    print('')