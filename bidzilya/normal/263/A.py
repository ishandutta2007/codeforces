for i in xrange(5):
    s = raw_input()
    if (s.find('1') != -1): 
        print abs(2 - i) + abs(2 - s.find('1') / 2)