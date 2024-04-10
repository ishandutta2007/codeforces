string = input()
a = ""
l = []
for i in range(len(string)):
    if string[i] in "1234567890.":
        a += string[i]
    elif len(a) > 0:
        l += [a]
        a = ""
if len(a) > 0:
    l += [a]
summ = 0
for el in l:
    if len(el) >= 3 and el[-3] == ".":
        e = el[:-3]
        e2 = el[-2:]
        str1 = ""
        for i in range(len(e)):
            if e[i] != ".":
                str1 += e[i]
        summ += int(str1) + int(e2) / 100
    else:
        str1 = ""
        e = el
        for i in range(len(e)):
            if e[i] != ".":
                str1 += e[i] 
        summ += int(str1)        
summ = round(summ * 100) / 100
if summ - summ // 1 == 0:
    summ = int(summ)            
summ = str(summ) 
if "." in summ:
    if summ[-2] == ".":
        summ += "0"
    s1 = summ[:-3]
    ost = len(s1) % 3
    ans = s1[:ost]
    for i in range(len(s1) // 3):
        ans += "."
        ans += s1[ost + 3*i:ost+3 + 3*i]
    if ost == 0:
        ans = ans[1:]
    ans += "."    
    ans += summ[-2:]   
    print(ans)
else:
    s1 = summ
    ost = len(s1) % 3
    ans = s1[:ost]
    for i in range(len(s1) // 3):
        ans += "."
        ans += s1[ost + 3*i:ost+3*i+3]
    if ost == 0:
        ans = ans[1:]
    print(ans)