for _ in range(int(input())):
    s = input()
    if(s.find('R') > s.find('r') and s.find('G') > s.find('g') and s.find('B') > s.find('b')):
        print("YES")
    else:
        print("NO")